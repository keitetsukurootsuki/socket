local host, port = "*", 1234
local socket = required("socket")
local tcp = assert(socket.tcp())
tcp:connect(host,port);
tcp:send("connection established \n");
while 1 do
	local s, status, partial = tcp:receive()
	print(s or partial)
	print("Enter message: ")
	tcp:send(io.read().."\n");
	if status == "closed" then break end
end
tcp:close()