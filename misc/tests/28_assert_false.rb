require_relative "../lib/should_equal.rb"

file = "misc/files/#{File.basename(__FILE__)}"
test = "misc/files/#{File.basename(__FILE__, ".*")}.avm"
output = "misc/output/#{File.basename(__FILE__, ".*")}.txt"
r = system "./avm #{test} > #{output}"
if r
	fd = File.open(output, "rb")
	content = fd.read
	compare = "File: #{test}\n" + "Parser: Line 5: Types or values for assert don't match\n" + "Parser: Missing exit instruction\n"
    should_equal(compare, content, file)
else
	puts "Error returned by avm !".red
end