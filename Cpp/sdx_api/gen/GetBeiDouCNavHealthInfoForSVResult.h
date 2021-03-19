#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouCNavHealthInfoForSV
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health int  Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255
    ///

    class GetBeiDouCNavHealthInfoForSVResult;
    typedef std::shared_ptr<GetBeiDouCNavHealthInfoForSVResult> GetBeiDouCNavHealthInfoForSVResultPtr;
    
    
    class GetBeiDouCNavHealthInfoForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNavHealthInfoForSVResult();

      GetBeiDouCNavHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health);
  
      static GetBeiDouCNavHealthInfoForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health);
      static GetBeiDouCNavHealthInfoForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

