-- prime sieve
local sieve, primes = {}, {}
for i = 2, 1000000 do
  if not sieve[i] then
    primes[#primes+1] = i
    for j = i * 2, 1000000, i do
      sieve[j] = true
    end
  end
end

local sums = {}
for i = 1, #primes do
  sums[i] = 0
end
local consecs = 0
local maxprime = 2
while #sums > 0 do
  for i, v in ipairs(sums) do
    sums[i] = sums[i] + primes[i+consecs]
    if sums[i] < 1000000 and not sieve[sums[i]] then
      maxprime = sums[i]
    end
  end
  consecs = consecs + 1

  for i = #sums, 1, -1 do
    if sums[i] > 1000000 then
      table.remove(sums)
    else
      break
    end
  end
  if #sums > #primes - consecs then
    table.remove(sums)
  end
end
print(maxprime)
