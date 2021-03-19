#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou satellite autonomous health
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..35
    ///

    class GetBeiDouAutonomousHealthForSV;
    typedef std::shared_ptr<GetBeiDouAutonomousHealthForSV> GetBeiDouAutonomousHealthForSVPtr;
    
    
    class GetBeiDouAutonomousHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouAutonomousHealthForSV();

      GetBeiDouAutonomousHealthForSV(int svId);
  
      static GetBeiDouAutonomousHealthForSVPtr create(int svId);
      static GetBeiDouAutonomousHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

