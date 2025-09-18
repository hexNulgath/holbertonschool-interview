/**
 * reverse - Reverses the digits of an unsigned integer
 * @n: The number to be reversed
 *
 * Return: The reversed number
 */
unsigned long reverse(unsigned long n)
{
    unsigned long reversed = 0;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return (reversed);
}

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 *
 * Description: A palindrome reads the same backward as forward
 */
int is_palindrome(unsigned long n)
{
    return (n == reverse(n));
}
