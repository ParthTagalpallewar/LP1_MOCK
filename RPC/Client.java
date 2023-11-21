import java.util.Scanner;

public class Client implements MessageSender {

  public static void main(String[] args) {
    Client client = new Client();
    Server server = new Server(client);
    Scanner sc = new Scanner(System.in);
  
    String userinput;
    while(true){
      System.out.println("Enter Message to send");
      userinput = sc.nextLine();

      if(userinput.equals("Exit")) break;

      server.sendMessage(userinput);
    }
  }

  @Override
  public void onMessageSend(String message) {
    System.err.println("Server Response " + message);
  }
}
