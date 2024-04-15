#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaMacLtId.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------------------------------------------------------
    /// MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.
    ///              Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.
    ///

    class GetOsnmaMacLtIdResult;
    typedef std::shared_ptr<GetOsnmaMacLtIdResult> GetOsnmaMacLtIdResultPtr;
    
    
    class GetOsnmaMacLtIdResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaMacLtIdResult();

      GetOsnmaMacLtIdResult(int macLtId);

      GetOsnmaMacLtIdResult(CommandBasePtr relatedCommand, int macLtId);

      static GetOsnmaMacLtIdResultPtr create(int macLtId);

      static GetOsnmaMacLtIdResultPtr create(CommandBasePtr relatedCommand, int macLtId);
      static GetOsnmaMacLtIdResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** macLtId ****
      int macLtId() const;
      void setMacLtId(int macLtId);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaMacLtIdResult);
  }
}

