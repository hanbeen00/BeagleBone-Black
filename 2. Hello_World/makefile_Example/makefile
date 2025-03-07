$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(LDFLAGS) $(CPPFLAGS)

clean:
	rm -rf *.o $(TARGET)