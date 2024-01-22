#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - intilizes a variable of type struct dog
 *
 * @d: pointer to the variable
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
		d = malloc(sizeof(struct dog));

	d->name = name;
	d->age = age;
	d->owner = owner;
}
