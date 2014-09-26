<?php
/**
 * @file
 * uf_content_types.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function uf_content_types_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Information Architecture',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '026624af-377d-46ad-9635-ca57c01670e2',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '1162e5b2-4eec-41d7-9ea0-db07e929e836',
    ),
  );
  $terms[] = array(
    'name' => 'Developer Interaction',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '063c2e6b-b093-485a-abe4-7086c8554730',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    ),
  );
  $terms[] = array(
    'name' => 'User Interface Design',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '07565984-9d99-4bc9-adf6-df3f9f922a8f',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '1162e5b2-4eec-41d7-9ea0-db07e929e836',
    ),
  );
  $terms[] = array(
    'name' => 'Consulting and Product Ownership',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 71,
    'uuid' => '0f3b942f-cd70-4f33-95ab-31c12dd541bc',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Project Management',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 75,
    'uuid' => '10c5bf64-b428-48dc-a04b-e3be55574d2d',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Interaction Design',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 65,
    'uuid' => '1162e5b2-4eec-41d7-9ea0-db07e929e836',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Ethnographic Research',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '137906b6-0218-413e-9182-0f1f99d2cca0',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'd9f7845e-19d1-4b8b-a4cd-69a6acab3766',
    ),
  );
  $terms[] = array(
    'name' => 'Summative Usability Testing',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '14837b4a-250a-4ba0-8dac-dad9813ff0c8',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '52b4ac9b-bc4b-46b8-b370-9c34814ea033',
    ),
  );
  $terms[] = array(
    'name' => 'Accessibility',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '19c54252-4d8a-4022-a87e-241762eb3930',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '97db70cf-ac8f-4529-9f0a-a071e9b6e55c',
    ),
  );
  $terms[] = array(
    'name' => 'Dev Ops',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 73,
    'uuid' => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Project Deployment Strategies',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '24db360f-1780-4ecc-beed-3ee45f56ab97',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    ),
  );
  $terms[] = array(
    'name' => 'Content Strategy',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '254aefb7-1081-48ed-bdcb-ec5029a84e04',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '1162e5b2-4eec-41d7-9ea0-db07e929e836',
    ),
  );
  $terms[] = array(
    'name' => 'Motivation',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '25c46390-0dd5-46b1-b0ad-42e20763f944',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Execution',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '2766112c-277c-4f87-bd34-6ffe1be359f7',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Language Fundamentals',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2adef567-6718-41cc-84ec-45d421f1b069',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'feb0dc6a-4e54-4e40-8918-370a1455e8d4',
    ),
  );
  $terms[] = array(
    'name' => 'ServerSide',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '2d6eb009-5266-4fda-a5ca-38930bd7eb53',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '746ab7dc-69cd-4469-8213-09918da3ca7b',
    ),
  );
  $terms[] = array(
    'name' => 'Interactivity & Motion',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '37b11ea7-a34f-436b-8655-bccebc320c63',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '9500b9f0-56da-4d30-9d9c-1db2984c559c',
    ),
  );
  $terms[] = array(
    'name' => 'People and Interactions',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 74,
    'uuid' => '3a37c487-d6e6-4f61-912f-733732a839b6',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Quality',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '3b0a4063-c704-4167-84e1-38edf5152ae6',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Finance',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4236fb1a-942e-45f8-bee5-4f828796232f',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '0f3b942f-cd70-4f33-95ab-31c12dd541bc',
    ),
  );
  $terms[] = array(
    'name' => 'Legal',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '477bb18f-8f87-40cd-bff1-0f7e32edaa49',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '0f3b942f-cd70-4f33-95ab-31c12dd541bc',
    ),
  );
  $terms[] = array(
    'name' => 'Subject Matter Expertise',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '486ae042-01d7-47eb-b25b-7162ad94ffdd',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '886e8de5-fbdf-49fa-aa66-d77f4aa57a04',
    ),
  );
  $terms[] = array(
    'name' => 'Analysis & Synthesis',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '494a67dd-da0d-47a2-a014-d469f468913b',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'd9f7845e-19d1-4b8b-a4cd-69a6acab3766',
    ),
  );
  $terms[] = array(
    'name' => 'Graphical User Interface Design',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4bdf3bf5-430b-4253-a36f-0c3ae6149b53',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '9500b9f0-56da-4d30-9d9c-1db2984c559c',
    ),
  );
  $terms[] = array(
    'name' => 'Design Testing',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 66,
    'uuid' => '52b4ac9b-bc4b-46b8-b370-9c34814ea033',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Workshop Design and Facilitation',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '5a619aa3-acda-4fd7-b279-1a98dac4bd0f',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '3a37c487-d6e6-4f61-912f-733732a839b6',
    ),
  );
  $terms[] = array(
    'name' => 'Self-Development',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '5f3b16b0-5cfb-4fb1-9643-d622e70a72d3',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Site Building',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '67017cb1-783e-4603-8561-057bbdf7077a',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'b61a498c-f8f9-4e5d-8da8-f53a4665ad14',
    ),
  );
  $terms[] = array(
    'name' => 'CSS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6753d6a4-2904-4e03-93cf-5e620275a072',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '97db70cf-ac8f-4529-9f0a-a071e9b6e55c',
    ),
  );
  $terms[] = array(
    'name' => 'Environment Deployment Strategies',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '685a3892-62d0-4abd-b699-2173c8adc4de',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    ),
  );
  $terms[] = array(
    'name' => 'Language Fundamentals',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6f4e874c-f1d4-45c1-8724-dcafebdad345',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '746ab7dc-69cd-4469-8213-09918da3ca7b',
    ),
  );
  $terms[] = array(
    'name' => 'ClientSide',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '73ec81cc-b4a1-478e-a118-30edc56dff7a',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '746ab7dc-69cd-4469-8213-09918da3ca7b',
    ),
  );
  $terms[] = array(
    'name' => 'JavaScript',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 69,
    'uuid' => '746ab7dc-69cd-4469-8213-09918da3ca7b',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Developing Others',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '74db9eaa-dc8c-4258-acdd-dd918f978836',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Performance Optimization',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '76fb85d5-943d-46e7-90e9-4585344c3ec6',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    ),
  );
  $terms[] = array(
    'name' => 'Server Administration',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7941f87a-930d-4128-83ce-46d3b925fcf1',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    ),
  );
  $terms[] = array(
    'name' => 'Ideation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '7c0ebf0b-c273-4fe7-b9d8-73216e6c0cf3',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    ),
  );
  $terms[] = array(
    'name' => 'Creativity and Problem Solving',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '7f5b1420-abb8-4880-8e8c-830acac69f64',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Agile Methodologies',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '861e23f4-e281-4256-ae25-0dead19f05ac',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '10c5bf64-b428-48dc-a04b-e3be55574d2d',
    ),
  );
  $terms[] = array(
    'name' => 'Org Responsibility',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 72,
    'uuid' => '886e8de5-fbdf-49fa-aa66-d77f4aa57a04',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Team Building and Coaching',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '90c9d523-e4bd-46d6-899a-4225b8c74e09',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '3a37c487-d6e6-4f61-912f-733732a839b6',
    ),
  );
  $terms[] = array(
    'name' => 'Systems Design',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '91d294c6-31e0-488f-956a-0e28c0f29edb',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '1162e5b2-4eec-41d7-9ea0-db07e929e836',
    ),
  );
  $terms[] = array(
    'name' => 'Design Communication',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '92c7e67c-2e3c-48f1-bdab-59e91b9dd4ed',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    ),
  );
  $terms[] = array(
    'name' => 'Testing',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '93d373b3-969f-4c86-8c93-d7e7ca7b533e',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '746ab7dc-69cd-4469-8213-09918da3ca7b',
    ),
  );
  $terms[] = array(
    'name' => 'Visual Interface Design',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 35,
    'uuid' => '9500b9f0-56da-4d30-9d9c-1db2984c559c',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'SASS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '97a91da3-e3e9-41c9-acbf-0c1a6460ccfe',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '97db70cf-ac8f-4529-9f0a-a071e9b6e55c',
    ),
  );
  $terms[] = array(
    'name' => 'Front End',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 67,
    'uuid' => '97db70cf-ac8f-4529-9f0a-a071e9b6e55c',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Research Planning & Preparation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '9e5e849e-046e-4255-bf56-c4562fa97b5f',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'd9f7845e-19d1-4b8b-a4cd-69a6acab3766',
    ),
  );
  $terms[] = array(
    'name' => 'Planning and Organizing',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '9ea13a92-728c-419a-8663-88743459865c',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'JS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '9eeb417d-3b3f-437b-a058-7937996c5618',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '97db70cf-ac8f-4529-9f0a-a071e9b6e55c',
    ),
  );
  $terms[] = array(
    'name' => 'Monitoring',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'a1d21f1f-f3d2-44c4-a73c-02fabb1620a8',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '21098c7a-bb83-48c3-9fbc-9b15cf58b700',
    ),
  );
  $terms[] = array(
    'name' => 'Data Visualization',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'a301eaed-48f6-431a-8fb3-fe6a72d22b34',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '9500b9f0-56da-4d30-9d9c-1db2984c559c',
    ),
  );
  $terms[] = array(
    'name' => 'Leadership',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'b1c1145e-25bd-4146-aa92-f159691314ca',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Communication',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'b28467a7-cb3b-431a-9781-bf04e22a7b8c',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Drupal',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 70,
    'uuid' => 'b61a498c-f8f9-4e5d-8da8-f53a4665ad14',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Collaboration',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'b6df1a8f-7bc8-4f8e-9933-41586d8580ee',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Adaptability',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bb824cad-1159-407b-97aa-594c8156187c',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Decision Making',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'c06ca2c6-cf35-498f-9d27-f369b53844a9',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Critique',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'c513ec7a-ed14-4e3d-bfc8-b0ae955ba181',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    ),
  );
  $terms[] = array(
    'name' => 'Facilitation',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cd6880d1-dc5e-43d3-af58-71056d23fde3',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '3a37c487-d6e6-4f61-912f-733732a839b6',
    ),
  );
  $terms[] = array(
    'name' => 'Application Frameworks',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd6b9528a-40ef-49e4-8cd7-f88f231ccdab',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'feb0dc6a-4e54-4e40-8918-370a1455e8d4',
    ),
  );
  $terms[] = array(
    'name' => 'Integrity',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => 'd87d7377-ea78-41c0-bab3-d4cda0fa10cb',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    ),
  );
  $terms[] = array(
    'name' => 'Design Research',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 50,
    'uuid' => 'd9f7845e-19d1-4b8b-a4cd-69a6acab3766',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Product Knowledge and Value',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'deb2169f-ce65-412b-a47e-dd746a426500',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '0f3b942f-cd70-4f33-95ab-31c12dd541bc',
    ),
  );
  $terms[] = array(
    'name' => 'Testing',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'deda221a-daf8-4122-a197-6ab229674bc3',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'feb0dc6a-4e54-4e40-8918-370a1455e8d4',
    ),
  );
  $terms[] = array(
    'name' => 'Formative Usability Testing',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e00c0e33-56ca-4803-bc09-97cfbaae71a1',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '52b4ac9b-bc4b-46b8-b370-9c34814ea033',
    ),
  );
  $terms[] = array(
    'name' => 'Client Interaction',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'e4986140-af18-4196-98a4-1ae78e847b27',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '3a37c487-d6e6-4f61-912f-733732a839b6',
    ),
  );
  $terms[] = array(
    'name' => 'Analytics and Metrics',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'e8dea14f-005a-4d80-8f05-1807825c7c00',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '10c5bf64-b428-48dc-a04b-e3be55574d2d',
    ),
  );
  $terms[] = array(
    'name' => 'Design Fundamentals',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Theming',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'ef08f5c4-d1d8-4594-92e1-d48a5a2d8dcc',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'b61a498c-f8f9-4e5d-8da8-f53a4665ad14',
    ),
  );
  $terms[] = array(
    'name' => 'Heuristic Evaluation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'ef1a8846-f33b-47a4-ade6-a923b713c47f',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '52b4ac9b-bc4b-46b8-b370-9c34814ea033',
    ),
  );
  $terms[] = array(
    'name' => 'Backlog Management',
    'description' => 'Child',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f2ffebdf-462f-4612-ba2a-496f8b092581',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => '10c5bf64-b428-48dc-a04b-e3be55574d2d',
    ),
  );
  $terms[] = array(
    'name' => 'Design Strategy',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f845f98d-4dec-4d0f-b386-19b1901ae2b9',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'ee3a863f-14f6-4e64-a2e5-fdb2d379518c',
    ),
  );
  $terms[] = array(
    'name' => 'Operational Compencies',
    'description' => 'Parent',
    'format' => 'plain_text',
    'weight' => 76,
    'uuid' => 'f944546e-8f61-4a18-afd9-33f9bcaf5a63',
    'vocabulary_machine_name' => 'skill',
  );
  $terms[] = array(
    'name' => 'Survey Research',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fd6039d4-8927-4966-ad18-b316c2d4d8b8',
    'vocabulary_machine_name' => 'skill',
    'parent' => array(
      0 => 'd9f7845e-19d1-4b8b-a4cd-69a6acab3766',
    ),
  );
  $terms[] = array(
    'name' => 'PHP',
    'description' => 'parent',
    'format' => 'plain_text',
    'weight' => 68,
    'uuid' => 'feb0dc6a-4e54-4e40-8918-370a1455e8d4',
    'vocabulary_machine_name' => 'skill',
  );
  return $terms;
}
