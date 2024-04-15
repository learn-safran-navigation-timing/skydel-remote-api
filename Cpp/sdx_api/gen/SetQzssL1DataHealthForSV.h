#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L1 C/A nav data health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      int             Data health 0..7
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssL1DataHealthForSV;
    typedef std::shared_ptr<SetQzssL1DataHealthForSV> SetQzssL1DataHealthForSVPtr;
    
    
    class SetQzssL1DataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssL1DataHealthForSV();

      SetQzssL1DataHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssL1DataHealthForSVPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssL1DataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

