#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou satellite health info
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health int  Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511
    ///

    class SetBeiDouHealthInfoForSV;
    typedef std::shared_ptr<SetBeiDouHealthInfoForSV> SetBeiDouHealthInfoForSVPtr;
    
    
    class SetBeiDouHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouHealthInfoForSV();

      SetBeiDouHealthInfoForSV(int svId, int health);
  
      static SetBeiDouHealthInfoForSVPtr create(int svId, int health);
      static SetBeiDouHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

