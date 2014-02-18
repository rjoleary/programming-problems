-- prime sieve
local sieve = {}
for i = 2, 1000000 do
  if sieve[i] == 4 and sieve[i+1] == 4 and sieve[i+2] == 4 and sieve[i+3] == 4 then
    print(i)
    break
  end
  if not sieve[i] then
    for j = i * 2, 1000000, i do
      if not sieve[j] then
        sieve[j] = 0
      end
      sieve[j] = sieve[j] + 1
    end
  end
end
