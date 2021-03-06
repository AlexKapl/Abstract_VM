require 'bigdecimal'
require_relative "../lib/should_equal.rb"

file = "misc/files/#{File.basename(__FILE__)}"
test = "misc/files/#{File.basename(__FILE__, ".*")}.avm"
output = "misc/output/#{File.basename(__FILE__, ".*")}.txt"
r = system "./avm #{test} > #{output}"

fd = File.open(output, "rb")
content = fd.read
compare = "File: #{test}\n" + "#{42 / 2 / 8 / 2 / 3.05 / 6 / 1 / 0.32}\n"
should_equal_n(compare, content, 8, file)
