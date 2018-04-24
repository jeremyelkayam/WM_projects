--author: Jeremy Elkayam

list = [1,2,3,4,5]

main = do
     -- [1,2,3,4,5] (the entire list, no alterations)
     print list

     -- 1 (first element only)
     print (head list)

     -- [2,3,4,5] (everything besides the first element)
     print (tail list)

     -- 5 (last element only)
     print (head (tail (tail (tail (tail list)))))

     -- [1,2,3,4] (all but last element)
     print (init list)

     -- 4 (second to last element)
     print (head (tail (tail (tail (init list)))))

     -- True (check if 3 is an element of list)
     print (elem 3 list)

     -- 5 (size of list)
     print (length list)

     -- False (check if list is empty)
     print (null list)

     -- [5,4,3,2,1] (reverse list)
     print (reverse list)

     -- [1,2] (first two elements)
     print (init (init (init list)))

     -- [3,4,5] (last three)
     print (tail (tail list))

     -- 1 (lowest value)
     print (minimum list)

     -- 5 (greatest value)
     print (maximum list)

     -- 15 (sum of all values)
     print (sum list)

     -- 120 (product of all values)
     print (product list)

     -- [1,4,9,16,25] (each element squared)
     print (maphead square list)

     -- False (check if every element is even)
     print (all even list)

     -- True (check if at least one element is odd)
     print (any odd list)

     -- [8,1,2,3,4,5] (concatenate 8 to front of list)

     -- "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (range of capital letters from A to Z)

     -- [3,9,15,18,21,27,30]

     -- [0,0,0,0,0,0,0,0,0,0]

     -- "abc" (concatenation of lists)

     -- [(1,'a'),(2,'b'),(3,'c')] (zip list)

     -- ([1,2,3],"abc") (unzip list)

     -- ["Hello","world"] (operation on "Hello world"