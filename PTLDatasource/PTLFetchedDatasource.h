//
//  PTLFetchedSection.h
//  PTLDatasource Demo
//
//  Created by Brian Partridge on 7/10/13.
//  Copyright (c) 2013 Pear Tree Labs. All rights reserved.
//

#import "PTLDatasource.h"
#import "PTLDatasource+TableView.h"
#import "PTLDatasource+CollectionView.h"
#import <CoreData/CoreData.h>

#ifdef _COREDATADEFINES_H

@interface PTLFetchedDatasource : PTLDatasource <PTLTableViewDatasource, PTLCollectionViewDatasource>

- (id)initWithFetchedResults:(NSFetchedResultsController *)controller;

@end

#endif