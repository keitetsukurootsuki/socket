import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
 
public class Server
{
 
    private static Socket socket;
 
    public static void main(String[] args)
    {
        try
        {
 
            int port = 25000;
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server Started and listening to the port 25000");
 
          
            while(true)
            {
                //Reading the message from the client
                socket = serverSocket.accept();
                InputStream input = socket.getInputStream();
                InputStreamReader read = new InputStreamReader(input);
                BufferedReader br = new BufferedReader(read);
                String msg = br.readLine();
                System.out.println("Message received from client is "+msg);
 
                try
                {
                 	char temp;
			char [] arr = msg.toCharArray();
			int len = arr.length;
			for (int i=0;i<(msg.length())/2;i++,len--)
			{
				temp = arr[i];
				arr[i] = arr[len-1];
				arr[len-1] = temp;
			}
			returnMsg + String.valueOf(arr) + "/n"
		}
	}
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                socket.close();
            }
            catch(Exception e){}
        }
    }
}