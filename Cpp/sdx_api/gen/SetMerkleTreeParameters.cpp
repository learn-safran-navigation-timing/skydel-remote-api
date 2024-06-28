
#include "SetMerkleTreeParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMerkleTreeParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMerkleTreeParameters::CmdName = "SetMerkleTreeParameters";
    const char* const SetMerkleTreeParameters::Documentation = "Set OSNMA Merkle Tree parameters. If ID is not set (or if new), a Merkle Tree is generated.\n"
      " Note that changing Merkle Tree parameters will modify its XML representation, and may result in Public Keys and Tree Nodes being regenerated.\n"
      "\n"
      "Name               Type              Description\n"
      "------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.\n"
      "KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : \"ECDSA P-256/SHA-256\" and \"ECDSA P-521/SHA-512\".\n"
      "                                     Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.\n"
      "HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : \"SHA-256\", \"SHA3-224\" and \"SHA3-256\".\n"
      "BeginApplicability datetime          Merkle Tree applicability begin date.\n"
      "EndApplicability   optional datetime Optional Merkle Tree applicability end date.";
    const char* const SetMerkleTreeParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetMerkleTreeParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetMerkleTreeParameters);


    SetMerkleTreeParameters::SetMerkleTreeParameters()
      : CommandBase(CmdName, TargetId)
    {}

    SetMerkleTreeParameters::SetMerkleTreeParameters(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setKeyType(keyType);
      setHashFunction(hashFunction);
      setBeginApplicability(beginApplicability);
      setEndApplicability(endApplicability);
    }

    SetMerkleTreeParametersPtr SetMerkleTreeParameters::create(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
    {
      return std::make_shared<SetMerkleTreeParameters>(id, keyType, hashFunction, beginApplicability, endApplicability);
    }

    SetMerkleTreeParametersPtr SetMerkleTreeParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMerkleTreeParameters>(ptr);
    }

    bool SetMerkleTreeParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::string>::is_valid(m_values["KeyType"])
          && parse_json<std::string>::is_valid(m_values["HashFunction"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["BeginApplicability"])
          && parse_json<std::optional<Sdx::DateTime>>::is_valid(m_values["EndApplicability"])
        ;

    }

    std::string SetMerkleTreeParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& SetMerkleTreeParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "KeyType", "HashFunction", "BeginApplicability", "EndApplicability"}; 
      return names; 
    }


    int SetMerkleTreeParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetMerkleTreeParameters::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMerkleTreeParameters::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMerkleTreeParameters::keyType() const
    {
      return parse_json<std::string>::parse(m_values["KeyType"]);
    }

    void SetMerkleTreeParameters::setKeyType(const std::string& keyType)
    {
      m_values.AddMember("KeyType", parse_json<std::string>::format(keyType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMerkleTreeParameters::hashFunction() const
    {
      return parse_json<std::string>::parse(m_values["HashFunction"]);
    }

    void SetMerkleTreeParameters::setHashFunction(const std::string& hashFunction)
    {
      m_values.AddMember("HashFunction", parse_json<std::string>::format(hashFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetMerkleTreeParameters::beginApplicability() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["BeginApplicability"]);
    }

    void SetMerkleTreeParameters::setBeginApplicability(const Sdx::DateTime& beginApplicability)
    {
      m_values.AddMember("BeginApplicability", parse_json<Sdx::DateTime>::format(beginApplicability, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<Sdx::DateTime> SetMerkleTreeParameters::endApplicability() const
    {
      return parse_json<std::optional<Sdx::DateTime>>::parse(m_values["EndApplicability"]);
    }

    void SetMerkleTreeParameters::setEndApplicability(const std::optional<Sdx::DateTime>& endApplicability)
    {
      m_values.AddMember("EndApplicability", parse_json<std::optional<Sdx::DateTime>>::format(endApplicability, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
