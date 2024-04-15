#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMerkleTreeXML.
    ///
    /// Name             Type      Description
    /// ---------------- --------- ---------------------------------------------------------------------------------------------------------------------------
    /// Id               string    Merkle Tree unique identifier.
    /// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.
    /// MerkleTreeXML    string    Merkle Tree XML representation.
    ///

    class GetMerkleTreeXMLResult;
    typedef std::shared_ptr<GetMerkleTreeXMLResult> GetMerkleTreeXMLResultPtr;
    
    
    class GetMerkleTreeXMLResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMerkleTreeXMLResult();

      GetMerkleTreeXMLResult(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML);

      GetMerkleTreeXMLResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML);

      static GetMerkleTreeXMLResultPtr create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML);

      static GetMerkleTreeXMLResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML);
      static GetMerkleTreeXMLResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** publicKeyIndexes ****
      std::vector<int> publicKeyIndexes() const;
      void setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes);


      // **** merkleTreeXML ****
      std::string merkleTreeXML() const;
      void setMerkleTreeXML(const std::string& merkleTreeXML);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMerkleTreeXMLResult);
  }
}

