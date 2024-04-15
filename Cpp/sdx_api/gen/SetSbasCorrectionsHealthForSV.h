#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply correction flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------
    /// SvId   int  The satellite's SV ID
    /// Health bool The correction unhealthy flag
    ///

    class SetSbasCorrectionsHealthForSV;
    typedef std::shared_ptr<SetSbasCorrectionsHealthForSV> SetSbasCorrectionsHealthForSVPtr;
    
    
    class SetSbasCorrectionsHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasCorrectionsHealthForSV();

      SetSbasCorrectionsHealthForSV(int svId, bool health);

      static SetSbasCorrectionsHealthForSVPtr create(int svId, bool health);
      static SetSbasCorrectionsHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    
  }
}

