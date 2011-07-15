require 'jcode'

def binary_encrypt(num)
  count = 0
  32.downto(0) {|i| count += num[i]}
  count
end

def hex_encrypt(numstr)
  count = 0
  numstr.each_char {|c| count += binary_encrypt(c.to_i)}
  count
end

gets
$stdin.each {|l| puts "#{binary_encrypt(l.to_i)} #{hex_encrypt(l.strip)}"}