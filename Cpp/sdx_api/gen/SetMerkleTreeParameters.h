#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA Merkle Tree parameters. If ID is not set (or if new), a Merkle Tree is generated.
    ///  Note that changing Merkle Tree parameters will modify its XML representation, and may result in Public Keys and Tree Nodes being regenerated.
    ///
    /// Name               Type              Description
    /// ------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.
    /// KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : "ECDSA P-256/SHA-256" and "ECDSA P-521/SHA-512".
    ///                                      Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.
    /// HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : "SHA-256", "SHA3-224" and "SHA3-256".
    /// BeginApplicability datetime          Merkle Tree applicability begin date.
    /// EndApplicability   optional datetime Optional Merkle Tree applicability end date.
    ///

    class SetMerkleTreeParameters;
    typedef std::shared_ptr<SetMerkleTreeParameters> SetMerkleTreeParametersPtr;
    
    
    class SetMerkleTreeParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetMerkleTreeParameters();

      SetMerkleTreeParameters(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability = {});

      static SetMerkleTreeParametersPtr create(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability = {});
      static SetMerkleTreeParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** keyType ****
      std::string keyType() const;
      void setKeyType(const std::string& keyType);


      // **** hashFunction ****
      std::string hashFunction() const;
      void setHashFunction(const std::string& hashFunction);


      // **** beginApplicability ****
      Sdx::DateTime beginApplicability() const;
      void setBeginApplicability(const Sdx::DateTime& beginApplicability);


      // **** endApplicability ****
      std::optional<Sdx::DateTime> endApplicability() const;
      void setEndApplicability(const std::optional<Sdx::DateTime>& endApplicability);
    };
    
  }
}

