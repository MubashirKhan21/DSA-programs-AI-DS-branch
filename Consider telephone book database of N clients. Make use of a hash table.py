class HashingDemo:
    def __init__(self):
        self.size = int(input("Enter the Size of the hash table: "))
        self.HashTable = list(0 for i in range(self.size))
        self.num_of_elements = 0
        self.comparisons = 0

    def isTableFull(self):
        if self.num_of_elements == self.size:
            return True
        else:
            return False

    def HashFun(self, element):
        return element % self.size

    def InsertElement_Linear(self, element):
        if self.isTableFull():
            print("Hash Table Full")
            return False

        OccupiedStatus = False
        position = self.HashFun(element)
        if self.HashTable[position] == 0:
            self.HashTable[position] = element
            print("Telephone Number " + str(element) + " at position " + str(position))
            OccupiedStatus = True
            self.num_of_elements += 1
        else:
            print("Collision has occurred for Telephone number " + str(element) + " at index " + str(position))
            position = self.LinearProbing(element, position)
            self.HashTable[position] = element
            OccupiedStatus = True
            self.num_of_elements += 1
        return OccupiedStatus

    def LinearProbing(self, element, position):
        while self.HashTable[position] != 0:
            position += 1
            if position >= self.size:
                position = 0
        return position

    def InsertElement_Quadratic(self, element):
        if self.isTableFull():
            print("Hash Table Full")
            return False

        OccupiedStatus = False
        position = self.HashFun(element)
        if self.HashTable[position] == 0:
            self.HashTable[position] = element
            print("Telephone Number " + str(element) + " at position " + str(position))
            OccupiedStatus = True
            self.num_of_elements += 1
        else:
            print("Collision Occurred for telephone number " + str(element) + " at index " + str(position))
            OccupiedStatus, position = self.quadraticProbing(element, position)
            if OccupiedStatus:
                self.HashTable[position] = element
                self.num_of_elements += 1
        return OccupiedStatus

    def quadraticProbing(self, element, position):
        Found = False
        limit = 50
        i = 1
        while i <= limit:
            newPosition = position + (i ** 2)
            newPosition = newPosition % self.size
            if self.HashTable[newPosition] == 0:
                Found = True
                break
            else:
                i += 1
        return Found, newPosition

    def search(self, element):
        found = False
        position = self.HashFun(element)
        self.comparisons += 1

        if self.HashTable[position] == element:
            return position

        temp = position - 1
        while position < self.size:
            if self.HashTable[position] != element:
                position += 1
                self.comparisons += 1
            else:
                return position

        position = temp
        while position >= 0:
            if self.HashTable[position] != element:
                position -= 1
                self.comparisons += 1
            else:
                return position

        if not found:
            print("Element not found")
            return False

    def display(self):
        print("\n")
        print("..................................................................")
        print("\n Position \t Telephone Number \n")
        print("..................................................................")
        for i in range(self.size):
            print("\t" + str(i) + "====>" + str(self.HashTable[i]))

# main function
hash_object1 = HashingDemo()

print("\n Inserting the telephone numbers in the Hash Table ...\n")
print("\n Collision Resolution using linear Probing \n")
hash_object1.InsertElement_Linear(1111111112)
hash_object1.InsertElement_Linear(3333333331)
hash_object1.InsertElement_Linear(4444444417)
hash_object1.InsertElement_Linear(5555555590)
hash_object1.InsertElement_Linear(6666666621)
hash_object1.InsertElement_Linear(7777777788)
hash_object1.InsertElement_Linear(8888888840)
hash_object1.InsertElement_Linear(9999999977)

hash_object1.display()
print()

print("The position of number 3333333331 is: " + str(hash_object1.search(3333333331)))
print("The position of number 6666666621 is: " + str(hash_object1.search(6666666621)))
print("The position of number 9999999977 is: " + str(hash_object1.search(9999999977)))

print("\n ...............................................................................")
print("\n Total number of comparisons done for searching = " + str(hash_object1.comparisons))
print("\n .....................................................................................")
print("\n\n\n ********************************************************************************\n")

hash_object2 = HashingDemo()
print("\n Inserting the telephone numbers in the Hash Table ...")
print("\n Collision Resolution using Quadratic Probing \n")
hash_object2.InsertElement_Quadratic(1111111112)
hash_object2.InsertElement_Quadratic(3333333331)
hash_object2.InsertElement_Quadratic(4444444417)
hash_object2.InsertElement_Quadratic(5555555590)
hash_object2.InsertElement_Quadratic(6666666621)
hash_object2.InsertElement_Quadratic(7777777788)
hash_object2.InsertElement_Quadratic(8888888840)
hash_object2.InsertElement_Quadratic(9999999977)

hash_object2.display()
print()

print("The position of number 3333333331 is: " + str(hash_object2.search(3333333331)))
print("The position of number 6666666621 is: " + str(hash_object2.search(6666666621)))
print("The position of number 9999999977 is: " + str(hash_object2.search(9999999977)))

print("\n ..............................................................................")
print("\n Total number of comparisons done for searching = " + str(hash_object2.comparisons))
print("\n ...............................................................................")

