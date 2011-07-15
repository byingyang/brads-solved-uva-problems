#!/usr/bin/env ruby

require "fileutils"

prob = ARGV[0]

Dir.mkdir(prob) unless File.directory?(prob)
FileUtils.cp("template.cc", "#{prob}/#{prob}.cc")
FileUtils.touch "#{prob}/input.txt"
f = File.new("#{prob}/Makefile", "w")
f.puts "#{prob}: #{prob}.cc ; g++ -o #{prob} #{prob}.cc"
g = File.new("#{prob}/run", "w")
g.puts "make"
g.puts "./#{prob} < input.txt"
g.chmod(0776)