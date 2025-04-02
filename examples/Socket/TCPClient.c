#include <NeoC/Base/Exception/Exception.h>
#include <NeoC/Base/Environment.h>
#include <NeoC/Type/String.h>
#include <NeoC/Console.h>
#include <NeoC/System.h>
#include <NeoC/Socket.h>

#include <NeoC/Debug.h>

void main() $_ {
	Socket_t *cli = NULL;

	try {
		cli = Socket.NewTCPClient(String.New(u8"localhost"), 10001);

		for (int32_t i = 0;; i++) {
			String_t *str = String.NewFormat(u8"Hello %d.", i);
			Socket.Send(cli, str);
			Console.WriteLine(String.NewFormat(u8"[Client]> %s", String.Unpack(str)));

			System.USleep(100 * 1000);

			if (Socket.UpdateExists(cli)) {
				String_t *msg = Socket.Receive(cli);
				Console.WriteLine(String.NewFormat(u8"[Server]> %s", String.Unpack(msg)));
			}

			if (i == 10) {
				Socket.Disconnect(cli);
				break;
			}
		}
	} catch (Socket.Exception) {
		Console.WriteErrorLine(String.New(u8"[Socket.Exception] 通信エラー"));
	} catchN (Socket.DisconnectionException) {
		Console.WriteErrorLine(String.New(u8"[Socket.DisconnectionException] 切断されました"));
	} finally {
		Socket.Delete(cli);
	} end
} _$
