cases = gets
cases.to_i.times do
  days = gets
  nparties = gets
  arr = Array.new
  nparties.to_i.times do
    party = gets
    arr << party.to_i
  end
  ctr = 0
  count = 0
  1.upto(days.to_i) do |day|
    ctr += 1
    arr.each do |party|
      if ((day % party).zero?) && (ctr != 6) && (ctr != 7)
        count += 1
        break
      end
    end
    ctr = 0 if ctr >= 7
  end
  puts count
end