#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export an OSNMA Merkle Tree to an XML file with the format defined in the Galileo OSNMA IDD ICD.
    ///
    /// Name             Type      Description
    /// ---------------- --------- ----------------------------------------------------------------------------------------------------------
    /// Id               string    Merkle Tree unique identifier.
    /// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, all Public Keys will be exported.
    /// FilePath         string    Export file path for the Merkle Tree.
    /// OverwriteFile    bool      When selected, existing file will be overwritten.
    ///

    class ExportMerkleTree;
    typedef std::shared_ptr<ExportMerkleTree> ExportMerkleTreePtr;
    
    
    class ExportMerkleTree : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportMerkleTree();

      ExportMerkleTree(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile);

      static ExportMerkleTreePtr create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile);
      static ExportMerkleTreePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** publicKeyIndexes ****
      std::vector<int> publicKeyIndexes() const;
      void setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes);


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** overwriteFile ****
      bool overwriteFile() const;
      void setOverwriteFile(bool overwriteFile);
    };
    
  }
}

