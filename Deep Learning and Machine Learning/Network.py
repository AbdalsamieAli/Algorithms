"""
A module to implement the stochastic gradient descent learing algorithm for a feedforward neural network. 
Gradients are calculated using backpropagation .
"""

### Libararies 
# Standard libarary 
import random 
# Third-party libaries
import numpy as np

class Network(object):
    def __init__(self, sizes):
        """
        The list ''sizes'' contains the number of neurons in the respective layers of the network.
        For example , if the list was [2, 3, 1] then it would be a three-layer network, with the
        first layer containing 2 neurons, the second layer 3 neurons, and the third layer 1 neuron. 
        Ther biases and wights for the network are initialized randomly, using a Gaussian 
        distribution with mean 0, and variance 1.
        """
        self.num_layers = len(sizes)
        self.sizes = sizes
        self.biases = [np.random.randn(y, 1) for y in sizes[1:]]
        self.weights = [np.random.randn(y, x) for x, y in zip(sizes[:-1], sizes[1:])]
        
    def feedforward(self, a):
        """
        Return the output of the network if ''a'' is input.
        """
        for b, w in zip(self.biases, self.weights):
                a = sigmoid(np.dot(w, a) + b)
        
        return a
    
    def SGD(self, training_data, epochs, mini_batch_size, eta, test_data=None):
        """
        Train the neural network using mini- batch stochastic gradient descent. The ''training_data''
        is a list of tuples ''(x, y)'' representing the trainging inputs and the desired 
        self-explanatory. If ''test_data'' is provided the the network will be evaluted
        against the test data after each epoch, and partial progress, but slows things down substantially.
        """
        if test_data:
            n_test = len(test_data)
        n = len (training_data)
        for j in xrange(epochs):
            random.shuffle(training_data)
            mini_batches = [
            training_data[k:k+mini_batch_size]
            for k in xrange(0, n, mini_batch_size)
            ]