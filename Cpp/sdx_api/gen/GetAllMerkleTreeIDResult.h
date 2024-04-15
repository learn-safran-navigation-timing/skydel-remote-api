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
    /// Result of GetAllMerkleTreeID.
    ///
    /// Name Type         Description
    /// ---- ------------ ----------------------------------------
    /// Ids  array string Array of Merkle Trees unique identifiers
    ///

    class GetAllMerkleTreeIDResult;
    typedef std::shared_ptr<GetAllMerkleTreeIDResult> GetAllMerkleTreeIDResultPtr;
    
    
    class GetAllMerkleTreeIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMerkleTreeIDResult();

      GetAllMerkleTreeIDResult(const std::vector<std::string>& ids);

      GetAllMerkleTreeIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllMerkleTreeIDResultPtr create(const std::vector<std::string>& ids);

      static GetAllMerkleTreeIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllMerkleTreeIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMerkleTreeIDResult);
  }
}

