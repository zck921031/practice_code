# -*- coding: utf-8 -*-
"""
Created on Sat Aug 27 16:36:37 2016

@author: zck
"""
import pandas,os
import h5py

if __name__ == '__main__':
    root ='data'
    df = pandas.read_csv( os.path.join(root, 'train.csv') )
    data = df.values
    y_train = data[:, 0].astype('float32')
    x_train = data[:, 1:].astype('float32')
    x_train = x_train.reshape(-1,1,28,28) / 255.
    with h5py.File( os.path.join(root, 'mnist_train.h5'), 'w') as f:
        f['data'] = x_train
        f['label'] = y_train
    
    df = pandas.read_csv( os.path.join(root, 'test.csv') )
    x_test = df.values.astype('float32')
    x_test = x_test.reshape(-1,1,28,28) / 255.
    with h5py.File( os.path.join(root, 'mnist_test.h5'), 'w') as f:
        f['data'] = x_test
    
    