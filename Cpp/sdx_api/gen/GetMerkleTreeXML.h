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
    /// Get Get an OSNMA Merkle Tree XML representation with the format defined in the Galileo OSNMA IDD ICD.
    ///
    /// Name             Type      Description
    /// ---------------- --------- ---------------------------------------------------------------------------------------------------------------------------
    /// Id               string    Merkle Tree unique identifier.
    /// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.
    ///

    class GetMerkleTreeXML;
    typedef std::shared_ptr<GetMerkleTreeXML> GetMerkleTreeXMLPtr;
    
    
    class GetMerkleTreeXML : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMerkleTreeXML();

      GetMerkleTreeXML(const std::string& id, const std::vector<int>& publicKeyIndexes);

      static GetMerkleTreeXMLPtr create(const std::string& id, const std::vector<int>& publicKeyIndexes);
      static GetMerkleTreeXMLPtr dynamicCast(CommandBasePtr ptr);
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
    };
    
  }
}

