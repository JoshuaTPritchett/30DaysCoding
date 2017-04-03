package server;

public class ServerMain {
	
	public static void main(String  []argv) {
		
		Server server = new BasicServer(8080);
		
		if (server.serverStart())
			System.out.println("System start successful");
	}
}
