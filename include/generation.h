#pragma once
#include "article.h"
#include <stdio.h>
#include "list.h"




/**
 * @brief A function for generating one random article
 * 
 * @return Article 
 */
Article generate_article();
/**
 * @brief Function for generating a list of random scientific articles
 * 
 * @param count 
 * @return List* 
 */
List* generate_list(u_int count);