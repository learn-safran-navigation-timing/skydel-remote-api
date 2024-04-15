#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Merkle Tree parameters.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------------------------------
    /// Id   string Merkle Tree unique identifier. Automatically set for new Merkle Trees.
    ///

    class GetMerkleTreeParameters;
    typedef std::shared_ptr<GetMerkleTreeParameters> GetMerkleTreeParametersPtr;
    
    
    class GetMerkleTreeParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMerkleTreeParameters();

      GetMerkleTreeParameters(const std::string& id);

      static GetMerkleTreeParametersPtr create(const std::string& id);
      static GetMerkleTreeParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

