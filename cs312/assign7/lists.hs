--author: Jeremy Elkayam

list = [1,2,3,4,5]

main = do
     -- [1,2,3,4,5] (the entire list, no alterations)
     print list

     -- 1 (first element only)
     print (head list)

     -- [2,3,4,5] (everything besides the first element)
     print (tail list)