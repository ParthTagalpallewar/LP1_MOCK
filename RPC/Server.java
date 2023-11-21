public class Server {

  MessageSender messageSender;

  public Server(MessageSender sender) {
    messageSender = sender;
    System.out.println("Connection with server is successful");
  }

  public void sendMessage(String message) {
    System.out.println("Message Received from client ");
    System.out.println("Sending Response to client ");

    messageSender.onMessageSend("Server Response : " + message);
  }
}
