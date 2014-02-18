-- prime sieve
local primes, sieve = {}, {}
for i = 2, 10000 do
  if not sieve[i] then
    primes[#primes+1] = i
    for j = i * 2, 10000, i do
      sieve[j] = true
    end
  end
end

function is4distinctprimes(n)
  local factors = 0
  for i, v in ipairs(primes) do
    if n % v == 0 then
      factors = factors + 1
      while n % v == 0 do
        n = n / v
      end
    end
    if n == 1 or factors > 4 then
      break
    end
  end
  
  return factors == 4
end

local starting = 0
for n = 1, math.huge, 4 do
  if is4distinctprimes(n) then
    local starting, ending
    for i = n - 1, 0, -1 do
      if not is4distinctprimes(i) then
        starting = i + 1
        break
      end
    end
    for i = n + 1, math.huge do
      if not is4distinctprimes(i) then
        ending = i - 1
        break
      end
    end
    if ending - starting + 1 == 4 then
      print(starting)
      break
    end
  end
end
