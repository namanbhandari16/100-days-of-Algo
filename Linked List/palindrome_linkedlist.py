# Python script to check if linked 
# list is palindrome or not using stack 
class Node: 
	def __init__(self,data): 
		
		self.data = data 
		self.next = None
		
# Function to check if the linked list 
# is palindrome or not 
def palindromeCheck(head): 
	
	# Temp pointer 
	slow = head 

	# Declaring a stack 
	stack = [] 
	
	ispalin = True

	# Push all elements of the list to the stack 
	while slow != None: 
		stack.append(slow.data) 
		
		# Move ahead 
		slow = slow.next

	# Iterate in the list again and 
	# check by popping from the stack 
	while head != None: 

		# Get the top most element from the stack
		i = stack.pop() 
		
		# Check if data is not 
		# same as popped element 
		if head.data == i: 
			ispalin = True
		else: 
			ispalin = False
			break

		# Move ahead 
		head = head.next
		
	return ispalin 

# Driver Code 

# Addition of linked list 
l1 = Node(1) 
l2 = Node(2) 
l3 = Node(4) 
l4 = Node(6) 
l5 = Node(4) 
l6 = Node(2) 
l7 = Node(1) 

# Initialize the next pointer 
# of every current pointer 
l1.next = l2 
l2.next = l3 
l3.next = l4 
l4.next = l5 
l5.next = l6 
l6.next = l7 
l7.next = None

# Call function to check palindrome or not 
result = palindromeCheck(l1) 

#Condition check of the returned result for providing the output
if result:
    print("The linked list is Palindrome")
else: 
    print("The linked list is not Palindrome") 


