require_relative "../lib/should_equal.rb"

file = "misc/files/#{File.basename(__FILE__)}"
test = "misc/files/#{File.basename(__FILE__, ".*")}.avm"
output = "misc/output/#{File.basename(__FILE__, ".*")}.txt"
r = system "./avm #{test} > #{output}"
if r
    fd = File.open(output, "rb")
    content = fd.read
	compare = "File: #{test}\n"
    should_equal(content, compare + "42\n", file)
else
    puts "Error returned by avm !".red
end