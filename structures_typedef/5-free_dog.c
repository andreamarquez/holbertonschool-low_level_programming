#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory from a dog type
 * variable given a pointer to it.
 * @p_dog_to_free: the pointer to a dog_t variable to free from
 * the memory.
 *
*/
void free_dog(dog_t *p_dog_to_free)
{
	if (p_dog_to_free == NULL)
	{
		return;
	}
	free(p_dog_to_free->name);
	free(p_dog_to_free->owner);
	free(p_dog_to_free);
}
