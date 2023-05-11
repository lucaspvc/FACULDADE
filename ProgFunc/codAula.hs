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

-----------------------------------------------------------------------

-- função que insere um elemento em uma lista ordenada

insere1::Int->[Int]->[Int]
insere1 a [] = [a]
insere1 a (b:x)
    |a<=b = a:(b:x)
    |otherwise = b:(insere1 a x)

ordenaL::[Int]->[Int]
ordenaL [] = []
ordenaL (a:x) = insere1 a (ordenaL x)

ordenaLL::[[Int]]->[[Int]]
ordenaLL [] = [] --Lista vazia casa com qualquer tipo de lista
ordenaLL (a:x) = ordenaL a : (ordenaLL x)

-----------------------------------------------------------------------
--função que ordena uma lista de duplas(Int,String)