----------------------------------------------------
-- Códigos desenvolvidos em sala
-- Lucas Pessoa Oliveira Alves
----------------------------------------------------

f1::(Int,Int,Bool)->(Int,Int,Bool)->Bool->(Int,Int,Bool)
f1 x y z
    |z = y
    |otherwise = x

f2::(Int,Int,Bool)->(Int,Int,Bool)->Bool->(Int,Int,Bool)
f2 x y _ 
    |ec y = x
    |otherwise = y

ec::(Int, Int,Bool)-> Bool
ec (_, _, a) = a

f3:: (Int,Int,Bool)->(Int,Int,Bool)->Bool->(Int,Int,Bool)
f3 x (y, z, b) _
    |b = x
    |otherwise = (y,z,b)

reverse1::[a]->[a]
reverse1 [] = []
reverse1 (z:x) = reverse (x)++[z]

--não deve fazer
r[]=[]
r(a:b:x)=r x ++[b,a]
r(a:x)=r x ++ [a]