namespace IO {
  const int BUFFER_SIZE = 1 << 15;
 
  char input_buffer[BUFFER_SIZE];
  size_t input_pos = 0, input_len = 0;
 
  void _update_input_buffer() {
    input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
    input_pos = 0;
 
    if (input_len == 0)
      input_buffer[0] = EOF;
  }
 
  inline char next_char(bool advance = true) {
    if (input_pos >= input_len)
      _update_input_buffer();
 
    return input_buffer[advance ? input_pos++ : input_pos];
  }
 
  template<typename T>
  inline void read_int(T &number) {
    bool negative = false;
    number = 0;
 
    while (!isdigit(next_char(false)))
      if (next_char() == '-')
        negative = true;
 
    do {
      number = 10 * number + (next_char() - '0');
    } while (isdigit(next_char(false)));
 
    if (negative)
      number = -number;
  }
 
  template<typename T, typename... Args>
  inline void read_int(T &number, Args &... args) {
    read_int(number);
    read_int(args...);
  }
}
