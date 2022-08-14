/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include <arrow-glib/arrow-glib.h>

#include <datafusion-glib/version.h>

G_BEGIN_DECLS

#define GDF_TYPE_CSV_READ_OPTIONS (gdf_csv_read_options_get_type())
G_DECLARE_DERIVABLE_TYPE(GDFCSVReadOptions,
                         gdf_csv_read_options,
                         GDF,
                         CSV_READ_OPTIONS,
                         GObject)
struct _GDFCSVReadOptionsClass
{
  GObjectClass parent_class;
};

GDF_AVAILABLE_IN_10_0
GDFCSVReadOptions *
gdf_csv_read_options_new(void);

GDF_AVAILABLE_IN_10_0
gboolean
gdf_csv_read_options_set_schema(GDFCSVReadOptions *options,
                                GArrowSchema *schema,
                                GError **error);
GDF_AVAILABLE_IN_10_0
GArrowSchema *
gdf_csv_read_options_get_schema(GDFCSVReadOptions *options);

GDF_AVAILABLE_IN_10_0
gboolean
gdf_csv_read_options_set_file_extension(GDFCSVReadOptions *options,
                                        const gchar *extension,
                                        GError **error);
GDF_AVAILABLE_IN_10_0
const gchar *
gdf_csv_read_options_get_file_extension(GDFCSVReadOptions *options);

GDF_AVAILABLE_IN_10_0
gboolean
gdf_csv_read_options_set_table_partition_columns(GDFCSVReadOptions *options,
                                                 const gchar **columns,
                                                 gsize n_columns,
                                                 GError **error);
GDF_AVAILABLE_IN_10_0
gchar **
gdf_csv_read_options_get_table_partition_columns(GDFCSVReadOptions *options);



G_END_DECLS
