




void Queue::enqueue(int num) {
    if (isFull())
        std::cout << "The queue is full.\n";
    else

    {
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Insert new item
        queueArray[rear] = num;
        // Update item count
        numItems++;
    }
}

