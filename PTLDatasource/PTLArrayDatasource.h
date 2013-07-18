//
//  PTLArraySection.h
//  PTLDatasource Demo
//
//  Created by Brian Partridge on 7/10/13.
//  Copyright (c) 2013 Pear Tree Labs. All rights reserved.
//

#import "PTLDatasource.h"
#import "PTLDatasource+TableView.h"
#import "PTLDatasource+CollectionView.h"

@interface PTLArrayDatasource : PTLDatasource <PTLTableViewDatasource, PTLCollectionViewDatasource>

- (id)initWithItems:(NSArray *)items;

- (void)addItem:(id)item;
- (void)addItemsFromArray:(NSArray *)items;
- (void)insertItem:(id)item atIndex:(NSInteger)index;

- (void)removeItem:(id)item;
- (void)removeItemAtIndex:(NSInteger)index;
- (void)removeAllItems;

- (void)moveItemAtIndex:(NSInteger)startIndex toIndex:(NSInteger)endIndex;

- (void)replaceItemAtIndex:(NSInteger)index withItem:(id)item;

- (BOOL)containsItem:(id)item;
- (NSIndexPath *)indexPathOfItem:(id)item;

@end
