local socket = require("socket")
local server = socket.try(socket.bind("*", 1234))
local ip, port = server:getsockname()
while 1 do
	local client = server:accept()
	client:settimeout(10)
	local line , err = client:receive()
	print(line)
	print("Enter input: ")
	if not err then client : send(io.read().."\n") end
	client : close
end