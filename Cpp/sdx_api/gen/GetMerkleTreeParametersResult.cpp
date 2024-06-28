
#include "GetMerkleTreeParametersResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMerkleTreeParametersResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMerkleTreeParametersResult::CmdName = "GetMerkleTreeParametersResult";
    const char* const GetMerkleTreeParametersResult::Documentation = "Result of GetMerkleTreeParameters.\n"
      "\n"
      "Name               Type              Description\n"
      "------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.\n"
      "KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : \"ECDSA P-256/SHA-256\" and \"ECDSA P-521/SHA-512\".\n"
      "                                     Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.\n"
      "HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : \"SHA-256\", \"SHA3-224\" and \"SHA3-256\".\n"
      "BeginApplicability datetime          Merkle Tree applicability begin date.\n"
      "EndApplicability   optional datetime Optional Merkle Tree applicability end date.";
    const char* const GetMerkleTreeParametersResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMerkleTreeParametersResult);


    GetMerkleTreeParametersResult::GetMerkleTreeParametersResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMerkleTreeParametersResult::GetMerkleTreeParametersResult(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setKeyType(keyType);
      setHashFunction(hashFunction);
      setBeginApplicability(beginApplicability);
      setEndApplicability(endApplicability);
    }

    GetMerkleTreeParametersResult::GetMerkleTreeParametersResult(CommandBasePtr relatedCommand, const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setKeyType(keyType);
      setHashFunction(hashFunction);
      setBeginApplicability(beginApplicability);
      setEndApplicability(endApplicability);
    }


    GetMerkleTreeParametersResultPtr GetMerkleTreeParametersResult::create(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
    {
      return std::make_shared<GetMerkleTreeParametersResult>(id, keyType, hashFunction, beginApplicability, endApplicability);
    }

    GetMerkleTreeParametersResultPtr GetMerkleTreeParametersResult::create(CommandBasePtr relatedCommand, const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability)
    {
      return std::make_shared<GetMerkleTreeParametersResult>(relatedCommand, id, keyType, hashFunction, beginApplicability, endApplicability);
    }

    GetMerkleTreeParametersResultPtr GetMerkleTreeParametersResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMerkleTreeParametersResult>(ptr);
    }

    bool GetMerkleTreeParametersResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::string>::is_valid(m_values["KeyType"])
          && parse_json<std::string>::is_valid(m_values["HashFunction"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["BeginApplicability"])
          && parse_json<std::optional<Sdx::DateTime>>::is_valid(m_values["EndApplicability"])
        ;

    }

    std::string GetMerkleTreeParametersResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMerkleTreeParametersResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "KeyType", "HashFunction", "BeginApplicability", "EndApplicability"}; 
      return names; 
    }


    std::string GetMerkleTreeParametersResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMerkleTreeParametersResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMerkleTreeParametersResult::keyType() const
    {
      return parse_json<std::string>::parse(m_values["KeyType"]);
    }

    void GetMerkleTreeParametersResult::setKeyType(const std::string& keyType)
    {
      m_values.AddMember("KeyType", parse_json<std::string>::format(keyType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMerkleTreeParametersResult::hashFunction() const
    {
      return parse_json<std::string>::parse(m_values["HashFunction"]);
    }

    void GetMerkleTreeParametersResult::setHashFunction(const std::string& hashFunction)
    {
      m_values.AddMember("HashFunction", parse_json<std::string>::format(hashFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetMerkleTreeParametersResult::beginApplicability() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["BeginApplicability"]);
    }

    void GetMerkleTreeParametersResult::setBeginApplicability(const Sdx::DateTime& beginApplicability)
    {
      m_values.AddMember("BeginApplicability", parse_json<Sdx::DateTime>::format(beginApplicability, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<Sdx::DateTime> GetMerkleTreeParametersResult::endApplicability() const
    {
      return parse_json<std::optional<Sdx::DateTime>>::parse(m_values["EndApplicability"]);
    }

    void GetMerkleTreeParametersResult::setEndApplicability(const std::optional<Sdx::DateTime>& endApplicability)
    {
      m_values.AddMember("EndApplicability", parse_json<std::optional<Sdx::DateTime>>::format(endApplicability, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
