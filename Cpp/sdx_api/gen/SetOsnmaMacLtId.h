#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA MAC look-up table ID.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------------------------------------------------------
    /// MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.
    ///              Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.
    ///

    class SetOsnmaMacLtId;
    typedef std::shared_ptr<SetOsnmaMacLtId> SetOsnmaMacLtIdPtr;
    
    
    class SetOsnmaMacLtId : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetOsnmaMacLtId();

      SetOsnmaMacLtId(int macLtId);

      static SetOsnmaMacLtIdPtr create(int macLtId);
      static SetOsnmaMacLtIdPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** macLtId ****
      int macLtId() const;
      void setMacLtId(int macLtId);
    };
    
  }
}

