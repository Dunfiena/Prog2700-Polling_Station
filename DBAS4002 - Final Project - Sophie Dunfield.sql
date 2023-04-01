DROP DATABASE if exists [DBAS4002-2023_ELECTION]
GO

CREATE DATABASE [DBAS4002-2023_ELECTION]
GO

USE [DBAS4002-2023_ELECTION]
GO

BEGIN TRANSACTION
DROP TABLE if exists Voters;
DROP TABLE if exists Addresses;
DROP TABLE if exists Contact;
DROP TABLE if exists PollingOfficer;
DROP TABLE if exists Payment;
DROP TABLE if exists Bank;
DROP TABLE if exists Candidate;
DROP TABLE if exists Voting_Station;
DROP TABLE if exists District;
DROP TABLE if exists Votes;
COMMIT
GO

---- THERE IS EXAMPLE DATA FOR EACH TABLE.  IT'S USE IF ONLY FOR THE PURPOSE OF SHOWING THE SYSTEM----
---- This information is purely invented for the purpose of this exercise and bears no resemblance---
---- to anyone, or any elections in the past.  Any information conresponding any person living, ----
---- fictional or dead is purely coincidental.  If you wish to remove test data simply add comment markers ----

BEGIN TRANSACTION
CREATE TABLE Voters(
	Registration# INT IDENTITY(1,1) PRIMARY KEY,
	FirstName VARCHAR(50) NOT NULL,
	LastName VARCHAR(50) NOT NULL,
	Date_of_Birth DATE NOT NULL,
	hasVoted TINYINT NOT NULL,
	AddressID INT NOT NULL,
	ContactID INT NOT NULL
);
INSERT INTO Voters
	VALUES('Dan','Brewer','1993-12-13', 0, 1, 1),
	('Benjamin','Brown','2001-11-04',0,2,2),
	('Steve','Stevens','1984-02-02',1,3,3);

CREATE TABLE Addresses(
	AddressID INT IDENTITY(1,1) PRIMARY KEY,
	House_number INT NOT NULL,
	Street_Name VARCHAR(50) NOT NULL,
	City VARCHAR(50) NOT NULL,
	Postal_Code VARCHAR(6) NOT NULL,
	DistrictID INT NOT NULL
);
INSERT INTO Addresses
	VALUES(47,'Orchard Dr','Wolfville','B4N4T6',1),
	(38,'Valley St','Kentville','B4N1T6',1),
	(76,'Terrace Ave','Hansport','B4K2F2', 1),
	(54,'Howser st','New Minas','B3N1T1',1),
	(34,'NewRoss st','Black Rock','B4T3L6',1),
	(56,'Terrace Ave','Hansport','B4K1F2',1),
	(2343,'Orchard st','Kentville','B4T5F5',1),
	(265,'NewRoss rd','New Minas','B4N7Y7',1),
	(989,'Oak rd','Hansport','B5N1N1',1),
	(111,'Main st','Wolfville','B4N7L8',1),
	(9902,'Main st','Kentvile','B6T3T1',1),
	(2,'Oak rd','New Minas','B4N3K3',1);

CREATE TABLE Contact(
	ContactID INT IDENTITY(1,1) PRIMARY KEY,
	DaytimeTelephone VARCHAR(12) NOT NULL,
	CellPhone VARCHAR(12),
	BuinessTelephone VARCHAR(12),
	EmailAddress VARCHAR(50)
);
INSERT INTO Contact
VALUES
('902-698-3455',null,null,'D.Brian@gmail.com'),
('902-234-2343','576-445-2222',null,'Benny@gmail.com'),
('902-234-1198','902-698-7798',null,'Steve.Steve@gmail.com'),

('902-398-9934',null, null,'Emily@gmail.com'),
('902-234-4444',null,'233-542-9485','Brain@gmail.com'),
('902-923-9923','233-904-0042','902-938-0010','Katie@gmail.com'),

('902-342-1232','902-234-1198', null, null),
('902-899-9342','902-484-2931','902-234-9922','Robert@gmail.com'),
('902-033-9183','902-839-7734',null, 'Emmm@gamil.com'),

('902-333-3232', null,null,null),
('902-681-1134', null, null, null),
('902-678-0012',null,null,null);

CREATE TABLE PollingOfficer(
	OfficerID INT IDENTITY(1,1) PRIMARY KEY,
	FirstName VARCHAR(50) NOT NULL,
	LastName VARCHAR(50) NOT NULL,
	Date_of_Birth DATE NOT NULL,
	AddressID INT NOT NULL,
	ContactID INT NOT NULL,
	SupervisorID INT,
	PaymentID INT NOT NULL,
	Password varchar(16) UNIQUE NOT NULL,
	--ADMIN ONLY, NULL OTHERWISE
	AdminID varchar(16)
);
INSERT INTO PollingOfficer
VALUES('Emily','Smith','20011003',4,4,null,1,'yu32123fd', null),
('Brian','Melson','19900404',5,5,1,2,'sdf2332dfs', null),
('Katie','Teten','19831108',6,6,1,3,'sdffdsdf23','admin123');

CREATE TABLE Payment(
	PaymentID INT IDENTITY(1,1) PRIMARY KEY,
	RateOfPay FLOAT NOT NULL,
	WeeklyPay TINYINT NOT NULL,
	ByDirectDeposit TINYINT NOT NULL,
	BankID INT UNIQUE 
);
INSERT INTO Payment
VALUES(25.30,1,1,1),
(18.60,1,1,2),
(32.13,0,1,3);

CREATE TABLE Bank(
	BankID INT IDENTITY(1,1) PRIMARY KEY,
	TransitNum INT NOT NULL UNIQUE,
	BranchNum INT NOT NULL,
	AccountNum INT NOT NULL UNIQUE
);
INSERT INTO Bank
VALUES(00734,001,065456),
(00123,007,123235),
(01354,011,435633);

CREATE TABLE Candidate(
	CandidateID INT IDENTITY(1,1) PRIMARY KEY,
	FirstName VARCHAR(50) NOT NULL,
	LastName VARCHAR(50) NOT NULL,
	Date_of_Birth DATE NOT NULL,
	AddressID INT NOT NULL,
	ContactID INT NOT NULL,
	DistrictID INT NOT NULL
);
INSERT INTO Candidate
VALUES('Thomas', 'How','19880521',7,7,1),
('Robert','Bobertson','19870430',8,8,1),
('Emeret','Clancey','19751109',9,9,1);

CREATE TABLE District(
	DistrictID INT IDENTITY(1,1) PRIMARY KEY,
	DistrictName VARCHAR(50)
);
INSERT INTO District
VALUES('Annapolis Valley'),
('Cumberland County'),
('Halifax Regional Municipality');

CREATE TABLE VotingStation(
	VotingStationID INT IDENTITY(1,1) PRIMARY KEY,
	SupervisorID INT NOT NULL,
	AddressID INT NOT NULL,
	ContactID INT NOT NULL,
	DistrictID INT NOT NULL
);
INSERT INTO VotingStation
VALUES(1,9,9,1),
(1,10,10,1),
(1,11,11,1);

CREATE TABLE Votes(
	VoteID INT IDENTITY(1,1) PRIMARY KEY,
	DateCast DATE NOT NULL,
	AdvancedVoting TINYINT NOT NULL,
	CandidateID INT NOT NULL,
	VotingStationID INT
);
INSERT INTO Votes
VALUES('20230101',1,1,1),
('20230101',1,3,1),
('20230101',1,3,1),
('20230101',1,2,1),
('20230105',0,1,1),
('20230108',0,3,1),
('20230105',0,2,1),
('20230108',0,1,1),
('20230103',0,1,1),
('20230105',0,3,1),
('20230206',0,1,1);
COMMIT


BEGIN TRANSACTION

ALTER TABLE Voters
	ADD FOREIGN KEY (AddressID) REFERENCES Addresses(AddressID);
ALTER TABLE Voters
	ADD FOREIGN KEY (ContactID) REFERENCES Contact(ContactID);

ALTER TABLE Addresses
	ADD FOREIGN KEY (DistrictID) REFERENCES District(DistrictID);

ALTER TABLE PollingOfficer
	ADD FOREIGN KEY (AddressID) REFERENCES Addresses(AddressID);
ALTER TABLE PollingOfficer
	ADD FOREIGN KEY (ContactID) REFERENCES Contact(ContactID);
ALTER TABLE PollingOfficer
	ADD FOREIGN KEY (SupervisorID) REFERENCES PollingOfficer(OfficerID);
ALTER TABLE PollingOfficer
	ADD FOREIGN KEY (PaymentID) REFERENCES Payment(PaymentID);

ALTER TABLE Payment
	ADD FOREIGN KEY (BankID) REFERENCES Bank(BankID);

ALTER TABLE Candidate
	ADD FOREIGN KEY (AddressID) REFERENCES Addresses(AddressID);
ALTER TABLE Candidate
	ADD FOREIGN KEY (ContactID) REFERENCES Contact(ContactID);
ALTER TABLE Candidate
	ADD FOREIGN KEY (DistrictID) REFERENCES District(DistrictID);

ALTER TABLE VotingStation
	ADD FOREIGN KEY (SupervisorID) REFERENCES PollingOfficer(OfficerID);
ALTER TABLE VotingStation
	ADD FOREIGN KEY (AddressID) REFERENCES Addresses(AddressID);
ALTER TABLE VotingStation
	ADD FOREIGN KEY (ContactID) REFERENCES Contact(ContactID);
ALTER TABLE VotingStation
	ADD FOREIGN KEY (DistrictID) REFERENCES District(DistrictID);

ALTER TABLE Votes
	ADD FOREIGN KEY (CandidateID) REFERENCES Candidate(CandidateID);
ALTER TABLE Votes
	ADD FOREIGN KEY (VotingStationID) REFERENCES VotingStation(VotingStationID);

COMMIT