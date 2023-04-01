
USE [DBAS4002-2023_ELECTION]
GO

--Register Candidate
INSERT INTO Candidate
VALUES(
-- Candidate First Name                                                                               --example  'Sophie'
''
,-- Candidate Last Name                                                                               --example  'Dunfield'
''
,-- Date of Birth (yyyy-mm-dd)                                                                        --example  1999-12-13
''
,--AddressID (See addresses to find proper office address *THIS IS NOT A HOME ADDRESS*)               -- Number existing on Addresses table

,-- ContactID (See contact table to find office contact information * THIS IS NOT A HOME CONTACT*)    -- Number existing on Contact table

,--DistrictID (See candidate form and district table for district ID)                                 -- Number existing on District table

);

--Register Voter
INSERT INTO Voter
VALUES( 
-- Voter First Name                                                                                   --example  'Sophie'
''
,-- Voter Last Name                                                                                   --example  'Dunfield'
''
,-- Date of Birth (yyyy-mm-dd)                                                                        --example  1999-12-13
''
,-- hasVoted (0 means no, 1 means yes)																  -- 0 or 1

,-- AddressID (See addresses to find proper home address)								              -- Number existing on Addresses table

,-- ContactID (See contact table to find home contact information)								      -- Number existing on Contact table

);

--Update Candidate Information
UPDATE Candidate
SET
-- Candidate First Name                                                                               --example  'Doug'
FirstName=''
,-- Candidate Last Name                                                                               --example  'Bennet'
LastName=''
,-- Date of Birth (yyyy-mm-dd)                                                                        --example  1984-01-09
Date_of_Birth=''
,--AddressID (See addresses to find proper office address *THIS IS NOT A HOME ADDRESS*)               -- Number existing on Addresses table
AddressId=
,-- ContactID (See contact table to find office contact information * THIS IS NOT A HOME CONTACT*)    -- Number existing on Contact table
ContactId=
,-- DistrictID (See candidate form and district table for district ID)                                 -- Number existing on District table
DistrictId=
-- Select which candidate you are altering by selecting their candidateID as seen in the candidate table
WHERE CandidateId= ;


--Update Voter Infomation Information
UPDATE Voters
SET
-- Voter First Name                                                                                   --example  'Doug'
FirstName=''
,-- Voter Last Name                                                                                   --example  'Bennet'
LastName=''
,-- Date of Birth (yyyy-mm-dd)                                                                        --example  1984-01-09
Date_of_Birth=''
,-- hasVoted (0 means no, 1 means yes)																  -- 0 or 1
hasVoted=
,--AddressID (See addresses to find proper office address *THIS IS NOT A HOME ADDRESS*)               -- Number existing on Addresses table
AddressId=
,-- ContactID (See contact table to find home contact information)								      -- Number existing on Contact table
ContactId=
-- Select which Voter you are altering by selecting their candidateID as seen in the candidate table
WHERE Registration#= ;

--Update Login credetials for Admin users
UPDATE PollingOfficer
SET
-- First Name             --example  'Doug'
FirstName=''
,-- Last Name             --example  'Bennet'
LastName=''
,-- Password              --example 'ert231$sd'
Password=''
,-- AdminID should only be entered if the user is the system admin, otherwise leave blank
AdminID=' '
-- Select with Officer's login you wish to update by selecting their ID as seen in PollingOfficer table
WHERE OfficerID= ;

-- Delete a specific User from database based on VoterID
-- as seen in the Voters Table
DELETE FROM Voters WHERE Registration#= ;

-- Delete a specific Polling Officer from database based on OfficerID
-- as seen in the PollingOfficer Table
DELETE FROM PollingOfficer WHERE OfficerID= ;

-- Delete a specific Candidate from database based on CandidateID
-- as seen in the Candidate Table
Delete From Votes WHERE CandidateID= ;
DELETE FROM Candidate WHERE CandidateID= ;


-- Delete all records from database
BEGIN TRANSACTION

Delete from Voters;
Delete from Votes;
Delete from VotingStation;
Delete from PollingOfficer;
Delete from Payment;
Delete from Bank;
Delete from Candidate;
Delete from Addresses;
Delete from District;
Delete from Contact;
COMMIT