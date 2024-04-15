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
    /// Set the SISA(E1,E5a) index of a Galileo satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Sisai       int             SISA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGalileoSisaE1E5aIndexForSV;
    typedef std::shared_ptr<SetGalileoSisaE1E5aIndexForSV> SetGalileoSisaE1E5aIndexForSVPtr;
    
    
    class SetGalileoSisaE1E5aIndexForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGalileoSisaE1E5aIndexForSV();

      SetGalileoSisaE1E5aIndexForSV(int svId, int sisai, const Sdx::optional<std::string>& dataSetName = {});

      static SetGalileoSisaE1E5aIndexForSVPtr create(int svId, int sisai, const Sdx::optional<std::string>& dataSetName = {});
      static SetGalileoSisaE1E5aIndexForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** sisai ****
      int sisai() const;
      void setSisai(int sisai);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

