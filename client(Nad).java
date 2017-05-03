import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.Socket;
 
public class Client
{
 
    private static Socket socket;
 
    public static void main(String args[])
    {
        try
        {
            String host = "192.168.118.1";
            int port = 25000;
            InetAddress address = InetAddress.getByName(host);
            socket = new Socket(address, port);
 
            //Send the message to the server
            OutputStream output = socket.getOutputStream();
            OutputStreamWriter writer = new OutputStreamWriter(output);
            BufferedWriter buffer = new BufferedWriter(writer);
 
            String msg = "Hello World";
 
            String sendMsg = msg + "\n";
            buffer.write(sendMsg);
            buffer.flush();
            System.out.println("Message sent to the server : "+sendMsg);
 
            //Get the return message from the server
            InputStream input = socket.getInputStream();
            InputStreamReader reader = new InputStreamReader(input);
            BufferedReader buffread = new BufferedReader(reader);
            String message = buffread.readLine();
            System.out.println("Message received from the server : " +message);
        }
        catch (Exception exception)
        {
            exception.printStackTrace();
        }
        finally
        {
            //Closing the socket
            try
            {
                socket.close();
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
    }
}