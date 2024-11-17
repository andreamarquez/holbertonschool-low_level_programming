#ifndef DOG_STRUCTURES
#define DOG_STRUCTURES

/**
 * struct dog - structure that contains the dog attributes
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Description: This structure is used to store information about a dog,
 * including its name, age, and owner.
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_STRUCTURES */

#ifndef DOG_FUNCTIONS
#define DOG_FUNCTIONS

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_FUNCTIONS */
