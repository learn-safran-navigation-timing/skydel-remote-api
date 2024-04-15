#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "date_time.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMerkleTreeParameters.
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

    class GetMerkleTreeParametersResult;
    typedef std::shared_ptr<GetMerkleTreeParametersResult> GetMerkleTreeParametersResultPtr;
    
    
    class GetMerkleTreeParametersResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMerkleTreeParametersResult();

      GetMerkleTreeParametersResult(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const Sdx::optional<Sdx::DateTime>& endApplicability = {});

      GetMerkleTreeParametersResult(CommandBasePtr relatedCommand, const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const Sdx::optional<Sdx::DateTime>& endApplicability = {});

      static GetMerkleTreeParametersResultPtr create(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const Sdx::optional<Sdx::DateTime>& endApplicability = {});

      static GetMerkleTreeParametersResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const Sdx::optional<Sdx::DateTime>& endApplicability = {});
      static GetMerkleTreeParametersResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
      Sdx::optional<Sdx::DateTime> endApplicability() const;
      void setEndApplicability(const Sdx::optional<Sdx::DateTime>& endApplicability);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMerkleTreeParametersResult);
  }
}

